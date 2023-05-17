# Mediator

```mermaid
classDiagram
direction TB
  class AbstractMediator {
    -_colleagues : std::vector~AbstractColleague*~
    +AbstractMediator()
    +~AbstractMediator()*
    +Add(colleague : AbstractColleague*) void
    +Consultation()* void
    +Kick()* void
  }
  class AbstractColleague {
    +AbstractColleague()
    +~AbstractColleague()*
    +Advice()* void
    +Set(mediator : AbstractMediator*)* void
  }
  class Mediator {
    +Mediator()
    +~Mediator()s
    +Consultation() void
  }
  class Colleague1 {
    +Colleague1()
    +~Colleague1()
    +Advice()
  }
  class Colleague2 {
    +Colleague2()
    +~Colleague2()
    +Advice()
  }
  
  AbstractMediator <|-- Mediator
  AbstractColleague <|-- Colleague1
  AbstractColleague <|-- Colleague2
  Mediator *-- Colleague1
  Mediator *-- Colleague2