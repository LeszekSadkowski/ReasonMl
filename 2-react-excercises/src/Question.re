/*
    <div class="question">
      <QuestionText />
      <div class="grid">
        <Answer />
        <Answer />
        <Answer />
        <Answer />
      </div>
    </div>
 */

[@react.component]
let make =
    (
      ~question: Core.question,
      ~onAnswerClick: Core.answerId => unit,
      ~answeringState: Core.answeringState,
    ) => {
  let answers =
    Belt.List.map(
      question.answers,
      answer => {
        let state =
          switch (answeringState) {
          | Highlighted(answerId) =>
            answerId == answer.id ? Answer.Highlighted : Answer.Initial
          | AnsweredCorrect(answerId) =>
            answerId == answer.id ? Answer.Correct : Answer.Initial
          | AnsweredWrong({answeredId}) when answeredId == answer.id => Answer.Wrong
          | AnsweredWrong({correctId}) when correctId == answer.id => Answer.Correct
          | _ => Answer.Initial
          };
        <Answer
          text={answer.text}
          id={answer.id}
          onClick=onAnswerClick
          state
        />;
      },
    );

  <div className="question">
    <QuestionText text={question.text} />
    <div> {React.array(Belt.List.toArray(answers))} </div>
  </div>;
};
