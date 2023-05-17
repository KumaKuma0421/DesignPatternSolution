# Decorator

```mermaid
classDiagram
direction TB
  class IComponent {
    <<Interface>>
    +~IComponent()*
    +Action()* bool
  }
  class Component {
    +Component()
    +~Component()
    +Action() bool
  }
  class Decorator {
    -_component : IComponent*
    +Decorator(component : IComponent*)
    +~Decorator()
    +Action() bool
    -Decorator()
  }

  IComponent <|-- Component
  IComponent <|-- Decorator
  Component <-- Decorator : use