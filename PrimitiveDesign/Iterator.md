# Iterator

```mermaid
classDiagram
direction TB
  class Item {
    <<Interface>>
    +Item()
    +~Item()*
  }
  class IAggregate {
    <<Interface>>
    +~IAggregate()
    +Iterator()* void
  }
  class IIterator {
    <<Interface>>
    +~IIterator()
    +HasNext()* void
    +Next()* void
  }
  class Aggregate {
    +Aggregate()
    +~Aggregate()
  }
  class Iterator {
    -_aggregate : std::vector~Aggregate~
    +Iterator()
    +~Iterator()
    +HasNext() void
    +Next() void
  }

  IAggregate <|-- Aggregate
  IIterator <|-- Iterator
  Iterator *-- Aggregate