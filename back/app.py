from dotenv import load_dotenv
from fastapi import FastAPI, responses
from pydantic import BaseModel
from pathlib import Path
from fastapi.responses import FileResponse
from fastapi.middleware.cors import CORSMiddleware
import os

# アプリケーション
from yume_prompt_agent import YumeService


workspace_path = Path("/workspaces/physiquest_animation_generator/backend/media/videos")

class Input(BaseModel):
    input: str

class Output(BaseModel):
    output: str

class Prompt(BaseModel):
    user_prompt: str
    video_id: str
    instruction_type: int

class DetailPrompt(BaseModel):
    user_prompt: str
    instruction_type: int

class Script(BaseModel):
    script: str

app = FastAPI(title='LangChain Server', version='1.0')

origins = ["http://localhost:3000"]

app.add_middleware(
    CORSMiddleware,
    allow_origins=origins,
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

yume_agent = YumeService()


@app.get("/")
async def root():
    return {"message": "Hello World"}

@app.get("/api/yume_question")
def generate_yume_question(yume_prompt:str):
    yume_question = yume_agent.generate_yume_question(yume_prompt)
    # json形式で返答する
    return responses.JSONResponse(content=yume_question,media_type="application/json")







if __name__ == '__main__':
    import uvicorn
    uvicorn.run(app, host='localhost', port=8000)