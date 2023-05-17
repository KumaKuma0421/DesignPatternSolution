# Prototype

```mermaid
classDiagram
direction TB
  class Prototype {
    -_bActive : bool
    -_iCounter : int
    -Take(const obj : Prototype&) void
    +Prototype()
    +Prototype(const obj : Prototype&)
    +~Prototype()*
    +Clone() Prototype*
    +operator = (const obj : Prototype&)
    +SetActive(bActive : bool) void
    +GetActive() : bool
    +SetCounter(iCounter : int) void
    +GetCounter() : int
  }