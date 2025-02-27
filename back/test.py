from langchain.schema.runnable import RunnablePassthrough

chain = (
    RunnablePassthrough().assign(
        chat_history = lambda x: '大阪です' # 修正
    )
    | RunnablePassthrough().assign(
        chat = lambda x: x["chat_history"],
    )
)

a=chain.invoke({"question":"何と答えましたか"})
print(a)