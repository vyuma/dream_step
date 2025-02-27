import DreamList from "../concrete-components/DreamList";
import DreamGraph from "../concrete-components/DreamGraph"; // 修正: DreamGraph にインポート先を変更
import DreamSummary from "../concrete-components/Chatbot";

export default function Page() {
  return (
    <div className="bg-rose-400" style={{ display: "flex", width: "100%" }}>
      <div style={{ flex: 6 }}>
        <DreamList />
      </div>

      <div
        style={{
          flex: 4,
          paddingLeft: "20px",
          display: "block",
        }}
      >
        <DreamGraph />
        <DreamSummary />
      </div>
    </div>
  );
}
