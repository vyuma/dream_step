import os
from dotenv import load_dotenv
import tomllib
from langchain_openai import ChatOpenAI
from langchain_google_genai import ChatGoogleGenerativeAI
from langchain.prompts import PromptTemplate
from langchain.schema.runnable import RunnableSequence
from langchain_core.output_parsers import StrOutputParser
from langchain.output_parsers import ResponseSchema
from langchain.output_parsers import ResponseSchema, StructuredOutputParser
from langchain.prompts import ChatPromptTemplate


load_dotenv('./.env.local')

class YumeService():
    def __init__(self):
        with open("./prompts.toml", 'rb') as f:
            self.prompts = tomllib.load(f)
        self.flash_llm_exp = self._load_llm("gemini-2.0-pro-exp-02-05")
        

    def _load_llm(self, model_type: str):
        if os.getenv('OPENAI_API_KEY'):
            return ChatOpenAI(model='gpt-4o-mini', temperature=0)
        return ChatGoogleGenerativeAI(model=model_type, google_api_key=os.getenv('GEMINI_API_KEY'))

    
    def generate_yume_question(self,yume_prompt:str):
        # 構造体の設定
        response_schemas = [
        ResponseSchema(
            name="Question", 
            description="配列形式の項目リスト。例: [{Question: string,Anser:string}]",
            type="array(objects)"
        )
        ]
        
        # パーサーの設定
        parser = StructuredOutputParser.from_response_schemas(response_schemas)
        # プロンプトの設定
        prompt_template=ChatPromptTemplate.from_template(
            template="""
            あなたは、夢を語る人に対してそれの具体化を支援するためのエージェントです。
            あなたは、次の夢をみる人たちにその夢が現実的に実現することができるように支援するアシスタントです。
            彼ら彼女らの夢はかなり抽象的であるので具体的に質問をしてより具体的な目標や夢に変換するための質問をしてください。
            質問:{yume_prompt}
            回答は以下のフォーマットを参照してください。
            {format_instructions}
            """,
            partial_variables={"format_instructions": parser.get_format_instructions()}
        )
        # Chainの実行
        chain = prompt_template | self.flash_llm_exp| parser
        result = chain.invoke({"yume_prompt": yume_prompt})
        return result
        
if __name__ == "__main__":
    yume_service = YumeService()
    output=yume_service.generate_yume_question("幸せになりたい！")
    print(output)
    