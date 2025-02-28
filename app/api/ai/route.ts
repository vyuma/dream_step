import { GoogleGenerativeAI } from "@google/generative-ai";
import { NextResponse } from "next/server";



export async function POST(request: Request) {
  if (!process.env.GOOGLE_API_KEY) {
    return new NextResponse("API key not found", { status: 500 });
  }
  const genAI = new GoogleGenerativeAI(process.env.GOOGLE_API_KEY);
  
  const encoder = new TextEncoder();
  const { prompt } = await request.json();
  const model = genAI.getGenerativeModel({ model: "gemini-2.0-pro-exp-02-05" });

  const result = await model.generateContentStream(prompt);
  const stream = new ReadableStream({
    async start(controller) {
      try {
        for await (const chunk of result.stream) {
          // レスポンスからテキストを抽出
          const text = chunk.text() || "";
          controller.enqueue(encoder.encode(text));
        }
        controller.close();
      } catch (error) {
        controller.error(error);
      }
    },
  });

  return new NextResponse(stream, {
    headers: {
      "Content-Type": "text/plain; charset=utf-8",
      "Cache-Control": "no-cache",
      "Transfer-Encoding": "chunked",
    },
  });
}
