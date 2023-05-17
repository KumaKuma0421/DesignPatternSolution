# Proxy

```mermaid
classDiagram
direction TB
  class ISubject {
    <<Interface>>
    +~ISubject()*
    +Action()* bool
    +HeavyAction()* bool
  }
  class Subject {
    +Subject()
    +~Subject()
    +Action() bool
    +HeavyAction() bool
  }
  class Proxy {
    +Proxy()
    +~Proxy()
    +Action() bool
    +HeavyAction() bool
  }

  ISubject <|-- Subject
  ISubject <|-- Proxy
  Proxy --> Subject