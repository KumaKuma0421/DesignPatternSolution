# Memento

```mermaid
classDiagram
direction TB
  class Memento {
    +~Memento()*
    -Memento()
    -friend class Originator
  }
  class Originator {
    -_memento : Memento*
    +Originator()
    +~Originator()*
    +CreateMemento() Memento*
    +SetMemento(memento : Memento*) void
  }
  class Caretaker {
    -_container : std::map < int, Memento* >
    +Caretaker()
    +~Caretaker()*
    +Set(number : int, memento : Memento*) void
    +Get(number : int) Memento*
  }
  
  Memento -- Originator
  Caretaker -- Memento