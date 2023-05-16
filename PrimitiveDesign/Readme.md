# PrimitiveDesign�v���W�F�N�g

PrimitiveProject�́AGoF�̃f�U�C���p�^�[�����ȗ������ăe���v���[�g�̂悤�ɂ������̂ł��B���ꎩ�̂ɂ͋@�\�͐��荞��ł��܂��񂪁A�\���̗����ɂ����p���������B

## �T�v

GoF�̃f�U�C���p�^�[���͂Q�R����A�J�e�S���͑傫���R�ɕ������܂��B

* �����Ɋւ���p�^�[��
* �\���Ɋւ���p�^�[��
* �U�镑���Ɋւ���p�^�[��

### �����Ɋւ���p�^�[��

|�p�^�[����|�T�v|
|----------|----|
|AbstractFactory|Factory Method�𓮓I�ɕϊ��\�ɂ���B|
|Builder|���G�ȃp�^�[���Ő��������I�u�W�F�N�g�̐������@���B������B|
|Factory Method|�I�u�W�F�N�g�̐�����S������N���X�𓝍��I�ɍ\������B|
|Prototype|�K�w�\���N���X�����N���X�ŊǗ��A�ێ�����B|
|Singleton|�P��̈��X�^���𐶐��A�񋟂���B|

### �\���Ɋւ���p�^�[��

|�p�^�[����|�T�v|
|----------|----|
|Adapter|�ύX�s�\�ȃI�u�W�F�N�g���݁A�ύX�\�ɂ���B|
|Bridge|���ۃC���^�[�t�F�[�X����āA�����I�u�W�F�N�g�ɃA�N�Z�X����B|
|Composite|�c���[�\����t�@�C��/�t�H���_�\����ێ�����B|
|Decorator|�C���X�^���X�ɓ��I�ɋ@�\��ǉ�����B|
|Facade|���ʃC���^�[�t�F�[�X��񋟂���B|
|Flyweight|�I�u�W�F�N�g��j�������A�ė��p����B|
|Proxy|�I�u�W�F�N�g�𒼐ڑ��삹���A��s������B|

### �U�镑���Ɋւ���p�^�[��

|�p�^�[����|�T�v|
|----------|----|
|Chain of Responsibility|�����̃I�u�W�F�N�g�𐔎�Ȃ��ɂ���B|
|Command|����Ɍĉ�����I�u�W�F�N�g��؂�ւ��Ďg�p����B|
|Interpreter|�\����͂��ăI�u�W�F�N�g�𐶐��A���s����B|
|Iterator|�I�u�W�F�N�g�̗v�f�ɏ��ԂɃA�N�Z�X����B|
|Mediator|�I�u�W�F�N�g�̑��ݎQ�Ƃ��\������B|
|Memento|�����̃I�u�W�F�N�g�𐶐��A���p����B|
|Observer|�C���X�^���X�̕ύX�Ď����@��񋟂���B|
|State|��ԂƃC�x���g���}�g���N�X��ɊǗ��A���s����B|
|Strategy|�A���S���Y���̐؂�ւ��Ǝ��s��񋟂���B|
|Template Method|�����p�^�[�����`���A�p����ɋ���������B|
|Visitor|�f�[�^�Ə����𕪗�����B|

## �N���X�}

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

## �V�[�P���X�}

## �p�r