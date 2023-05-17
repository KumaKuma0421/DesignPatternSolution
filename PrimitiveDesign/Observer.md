# Observer

```mermaid
classDiagram
direction LR
  class IObserver {
    <<Interface>>
    +~IObserver()*
    +Update()*
  }
  class Subscriber {
    -_observers : std::vector~IObserver*~
    +Subscriber()
    +~Subscriber()*
    +Add(observer : IObserver*)*
    +Notify()* void
  }
  class Observer1 {
    +Observer1()
    +~Observer1()
    +Update() void
  }
  class Observer2 {
    +Observer2()
    +~Observer2()
    +Update() void
  }
  class ConcreteSubscriber {
    +ConcreteSubscriber()
    +~ConcreteSubscriber()
  }

  IObserver <|-- Observer1
  IObserver <|-- Observer2
  Subscriber <|-- ConcreteSubscriber
  Subscriber --> IObserver : reference
  Subscriber *-- Observer1
  Subscriber *-- Observer2