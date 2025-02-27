'use server';

import {GoogleGenerativeAI} from "@google/generative-ai";

const genAI = new GoogleGenerativeAI("AIzaSyC81CIui393LUf0ZRmA4agGEhxnMvbDk7o")

export async function continueConversation(prompt: string) {
    const model = genAI.getGenerativeModel({ model: "gemini-2.0-pro-exp-02-05"});

    const data = { test: 'hello' };
    const result = await model.generateContentStream(prompt);
    console.log(result)
    return result.stream;
}