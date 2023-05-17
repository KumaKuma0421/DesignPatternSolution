# Visitor

```mermaid
classDiagram
direction TB
  class IAcceptor {
    <<Interface>>
    +~IAcceptor()*
    +Accept(visitor : IVisitor*)* void
    +Action()* void
  }
  class IVisitor {
    +~IVisitor()*
    +Visit(acceptor : Acceptor1*)* void
    +Visit(acceptor : Acceptor2*)* void
  }
  class Acceptor1 {
    +Acceptor1()
    +~Acceptor1()
    +Accept(visitor : IVisitor*) void
    +Action() void
  }
  class Acceptor2 {
    +Acceptor2()
    +~Acceptor2()
    +Accept(visitor : IVisitor*) void
    +Action() void
  }
  class Visitor1 {
    +Visitor1()
    +~Visitor1()
    +Visit(acceptor : Acceptor1*) void
    +Visit(acceptor : Acceptor2*) void
  }
  class Visitor2 {
    +Visitor2()
    +~Visitor2()
    +Visit(acceptor : Acceptor1*) void
    +Visit(acceptor : Acceptor2*) void
  }

  IAcceptor <|-- Acceptor1
  IAcceptor <|-- Acceptor2
  IAcceptor --> IVisitor
  IVisitor -- Acceptor1
  IVisitor -- Acceptor2
  IVisitor <|-- Visitor1
  IVisitor <|-- Visitor2
