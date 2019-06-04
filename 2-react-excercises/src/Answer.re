type state =
  | Initial
  | Highlighted
  | Correct
  | Wrong;

/*
   Initial:
   <div class="answer">
     A. Treść odpowiedzi
   </div>

   Highlighted:
   <div class="answer highlighted">
     B. Treść odpowiedzi
   </div>

   Correct:
   <div class="answer correct">
     C. Treść odpowiedzi
   </div>

   Wrong:
   <div class="answer wrong">
     D. Treść odpowiedzi
   </div>

 */
[@react.component]
let make =
    (
      ~text: string,
      ~id: Core.answerId,
      ~onClick: Core.answerId => unit,
      ~state: state,
    ) => {
  let mark = _ => {
    onClick(id);
  };
  let className =
    switch (state) {
    | Initial => "answer"
    | Highlighted => " answer highlighted"
    | Correct => "answer correct"
    | Wrong => "answer wrong"
    };
  <div className onClick=mark>
    {switch (id) {
     | A => React.string("A.")
     | B => React.string("B.")
     | C => React.string("C.")
     | D => React.string("D.")
     }}
    {React.string(text)}
  </div>;
};
