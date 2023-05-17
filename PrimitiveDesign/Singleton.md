# Singleton

```mermaid
classDiagram
direction LR
  class Singleton {
    -Singleton()
    -_instance : Singleton* [static]
    +~Singleton()
    +Instance()$ Singleton*
  }