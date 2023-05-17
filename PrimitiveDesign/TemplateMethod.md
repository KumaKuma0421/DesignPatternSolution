# TemplateMethod

```mermaid
classDiagram
direction TB
  class AbstractTemplateMethod {
    +AbstractTemplateMethod()
    +~AbstractTemplateMethod()
    +Action()* bool
    +Function1()* bool
    +Function2()* bool
    +Function3()* bool
  }
  class TemplateMethod {
    +TemplateMethod()
    +~TemplateMethod()
    +Function1() bool
    +Function2() bool
    +Function3() bool
  }

  AbstractTemplateMethod <|-- TemplateMethod