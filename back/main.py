from dotenv import load_dotenv
from fastapi import FastAPI, responses
from pydantic import BaseModel
from pathlib import Path
from fastapi.responses import FileResponse
from fastapi.middleware.cors import CORSMiddleware
import os



load_dotenv('./.env.local')
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


@app.get("/")
async def root():
    return {"message": "Hello World"}





if __name__ == '__main__':
    import uvicorn
    uvicorn.run(app, host='localhost', port=8000)