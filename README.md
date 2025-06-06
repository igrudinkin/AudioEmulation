## Пример кода для тестирования аудио на интеграционном стенде

#### Решаемая задача
Автоматизировать тестирование работы микрофона и динамика на устройстве (микрофон и динамик являются подключаемым к устройству оборудованием). Необходимо убедиться в качестве пайки компонентов на плате, а также в работоспособности GSM модуля. Обработка звука на устройстве осуществляется встроенными кодеками на GSM модеме.  

#### Принцип работы теста
- Тестируемая плата подключается к стенду 
- На стенде генерируется синусоидальный сигнал (используя ЦАП) и отправляется на вход микрофона тестируемой платы
- Тестируемое устройство непрерывно "слушает" подаваемый сигнал и ретранслирует его на аудио выход
- На стенде, после отправки сигнала, активируется АЦП и считывает получаемый от устройства сигнал
- Производится оценка полученного сигнала и сравнение его частоты и амплитуды с "эталонным" значением (методом БПФ)

#### Описание репозитория

Проект собирается с использованием CMake (не приведено в данном репозитории). 

*Решение написано в уже активном проекте и заимствует у него  структуру приложения, по этому взаимодействие между слоями может показаться не оптимальным*

Нижний уровень абстракции (MCU) представляет собой реализацию периферии используемого МК (STM32H7xx) с использованием CMSIS, LL и HAL. Реализация этого уровня скрыта из репозитория так как не является уникальным для этой задачи. 
#### Описание директорий
*applications* - располагается пример вызова теста аудио (взаимодействие со слоем BSP).

*components* - располагается реализация BSP для работы на интеграционном стенде и драйвера калькулятора частот.



