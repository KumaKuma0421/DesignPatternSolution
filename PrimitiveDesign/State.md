# State

```mermaid
classDiagram
direction TB
  class IState {
    <<Interface>>
    +~IState()*
    +Action()* void
  }
  class State1 {
    +State1()
    +~State2()
    +Action() void
  }
  class State2 {
    +State2()
    +~State2()
    +Action() void
  }
  class Invoker {
    -_state[2][2] : IState*
    -_status : int
    +Invoker()
    +~Invoker()*
    +Action(event : int)* void
  }

  IState <|-- State1
  IState <|-- State2
  Invoker --> State1 : create & use
  Invoker --> State2 : create & use