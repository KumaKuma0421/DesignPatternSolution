# FactoryMethod

```mermaid
classDiagram
direction LR
  class IProduct {
    <<Interface>>
    +~IProduct()*
    +Action()* void
  }
  class ICreator {
    <<Interface>>
    +~ICreator()*
    +CreateProduct()* IProduct*
  }
  class Product {
    +Product()
    +~Product()
    +Action() void
  }
  class Creator {
    +Creator()
    +~Creator()
    +CreateProduct() IProduct*
  }

  IProduct <|-- Product
  ICreator <|-- Creator
  Product <-- Creator : create