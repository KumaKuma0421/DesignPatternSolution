# Abstract Factory

```mermaid
classDiagram
  direction TB
  class IProduct1 {
    <<Interface>>
    +~IProduct1()*
    +Action1()* bool
  }
  class ProductA1 {
    +ProductA1()
    +~ProductA1()
    Action1() bool
  }
  class ProductB1 {
    +ProductB1()
    +~ProductB1()
    +Action1() bool
  }
  
  class IProduct2 {
    <<Interface>>
    +~IProduct2()*
    +Action2()* bool
  }
  class ProductA2 {
    +ProductA2()
    +~ProductA2()
    Action2() bool
  }
  class ProductB2 {
    +ProductB2()
    +~ProductB2()
    +Action2() bool
  }
  
  class IFactory {
    <<Interface>>
    +~IFactory()*
    +CreateProduct1()* IProduct1*
    +CreateProduct2()* IProduct2*
  }
  class FactoryA {
    +FactoryA()
    +~FactoryA()
    +CreateProduct1() IProduct1*
    +CreateProduct2() IProduct2*
  }
  class FactoryB {
    +FactoryB()
    +~FactoryB()
    +CreateProduct1() IProduct1*
    +CreateProduct2() IProduct2*
  }
  
  IFactory <|-- FactoryA
  IFactory <|-- FactoryB
  IProduct1 <|-- ProductA1
  IProduct1 <|-- ProductB1
  IProduct2 <|-- ProductA2
  IProduct2 <|-- ProductB2
  FactoryA --> ProductA1 : create
  FactoryA --> ProductA2 : create
  FactoryA --> IProduct1 : use
  FactoryA --> IProduct2 : use
  FactoryB --> ProductB1 : create
  FactoryB --> ProductB2 : create
  FactoryB --> IProduct1 : use
  FactoryB --> IProduct2 : use
```