
[@react.component]
let make = (~text:string) => {
  <div className="question-text">
    {React.string(text)}
  </div>;
};
