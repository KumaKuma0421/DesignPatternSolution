# Strategy

```mermaid
classDiagram
direction TB
  class IStrategy {
    <<Interface>>
    +~IStrategy()*
    +Action()* void
  }
  class Strategy1 {
    +Strategy1()
    +~Strategy1()
    +Action() void
  }
  class Strategy2 {
    +Strategy2()
    +~Strategy2()
    +Action() void
  }
  class Strategy3 {
    +Strategy3()
    +~Strategy3()
    +Action() void
  }
  class Invoker {
    -_container : std::map < int, IStrategy* >
    +Invoker()
    +~Invoker()*
    +Action(action : int)
  }

  IStrategy <|-- Strategy1
  IStrategy <|-- Strategy2
  IStrategy <|-- Strategy3
  Invoker --> Strategy1 : create & use
  Invoker --> Strategy2 : create & use
  Invoker --> Strategy3 : create & use