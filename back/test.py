from langchain.output_parsers import ResponseSchema
from langchain.output_parsers import StructuredOutputParser

# ResponseSchemaを使い、キーの名前と、入るべき値の説明を記述する。
brand_name_schema = ResponseSchema(name="brand_name", description="ブランド名")

likelihood_of_success_schema = ResponseSchema(name="likelihood_of_success", description="1から10のスコアで示された、成功する可能性")

reasoning_schema = ResponseSchema(name="reasoning", description="スコアの理由。これは日本語で記述されなければなりません。")

# ResponseSchemaをもとに、指示を作成する。
response_schemas = [brand_name_schema,
                    likelihood_of_success_schema,
                    reasoning_schema]

output_parser = StructuredOutputParser.from_response_schemas(response_schemas)
format_instructions = output_parser.get_format_instructions()
