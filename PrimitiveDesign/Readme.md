# PrimitiveDesignプロジェクト

PrimitiveProjectは、GoFのデザインパターンを簡略化してテンプレートのようにしたものです。これ自体には機能は盛り込んでいませんが、構造の理解にご利用ください。

## 概要

GoFのデザインパターンは２３個あり、カテゴリは大きく３つに分けられます。

* 生成に関するパターン
* 構造に関するパターン
* 振る舞いに関するパターン

### 生成に関するパターン

|パターン名|概要|
|----------|----|
|AbstractFactory|Factory Methodを動的に変換可能にする。|
|Builder|複雑なパターンで生成されるオブジェクトの生成方法を隠蔽する。|
|Factory Method|オブジェクトの生成を担当するクラスを統合的に構成する。|
|Prototype|階層構造クラスを基底クラスで管理、保持する。|
|Singleton|単一の員スタンを生成、提供する。|

### 構造に関するパターン

|パターン名|概要|
|----------|----|
|Adapter|変更不能なオブジェクトを包み、変更可能にする。|
|Bridge|抽象インターフェースを介して、実装オブジェクトにアクセスする。|
|Composite|ツリー構造やファイル/フォルダ構造を保持する。|
|Decorator|インスタンスに動的に機能を追加する。|
|Facade|共通インターフェースを提供する。|
|Flyweight|オブジェクトを破棄せず、再利用する。|
|Proxy|オブジェクトを直接操作せず、代行させる。|

### 振る舞いに関するパターン

|パターン名|概要|
|----------|----|
|Chain of Responsibility|複数のオブジェクトを数珠つなぎにする。|
|Command|操作に呼応するオブジェクトを切り替えて使用する。|
|Interpreter|構文解析してオブジェクトを生成、実行する。|
|Iterator|オブジェクトの要素に順番にアクセスする。|
|Mediator|オブジェクトの相互参照を構成する。|
|Memento|履歴のオブジェクトを生成、活用する。|
|Observer|インスタンスの変更監視方法を提供する。|
|State|状態とイベントをマトリクス状に管理、実行する。|
|Strategy|アルゴリズムの切り替えと実行を提供する。|
|Template Method|処理パターンを定義し、継承先に強制させる。|
|Visitor|データと処理を分離する。|

## クラス図

### Abstract Factory

### Adapter

<div class="mermaid">
classDiagram
  direction LR
  classA
  classB
  classC
  
  classA <|-- classB
  classA <|.. classC
  classB -- classC
</div>
<script src="https://unpkg.com/mermaid/dist/mermaid.min.js"></script>
<script>mermaid.initialize({startOnLoad:true});</script>

## シーケンス図

## 用途