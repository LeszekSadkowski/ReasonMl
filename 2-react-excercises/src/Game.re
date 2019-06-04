let firstQuestion = Core.firstQuestion;

type state = {
  prizes: list(Core.prize),
  currentPrizeIndex: int,
  answeringState: Core.answeringState,
};

type action =
  | SelectAnswer(Core.answerId);

let reducer = (state: state, action: action) => {
  let SelectAnswer(answerId) = action;
  switch (state.answeringState) {
  | NotHighlighted => {...state, answeringState: Highlighted(answerId)}
  | Highlighted(highlightedAnswerId) =>
    if (highlightedAnswerId == answerId) {
      firstQuestion.correctAnswerId == answerId
        ? {...state, answeringState: AnsweredCorrect(answerId)}
        : {
          ...state,
          answeringState:
            AnsweredWrong({
              answeredId: answerId,
              correctId: firstQuestion.correctAnswerId,
            }),
        };
    } else {
      {...state, answeringState: Highlighted(answerId)};
    }
  | _ => state
  };
};

let initialState = {
  prizes: Core.prizes,
  currentPrizeIndex: 0,
  answeringState: NotHighlighted,
};

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);

  <div className="root">
    <div className="left-column">
      <Logo />
      <Question
        question=firstQuestion
        onAnswerClick={id => dispatch(SelectAnswer(id))}
        answeringState={state.answeringState}
      />
    </div>
    <div className="right-column"> <NewGameButton /> <PrizeTrack /> </div>
  </div>;
};
