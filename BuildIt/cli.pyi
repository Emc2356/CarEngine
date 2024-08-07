from typing import overload, Callable


@overload
def unknown_argument(func: Callable[[str], bool]) -> Callable[[str], bool]: ...
@overload
def unknown_argument(func: Callable[[str, list[str]], int]) -> Callable[[str, list[str]], int]: ...
@overload
def handle_argv(argv: list[str]) -> None: ...
@overload
def handle_argv() -> None: ...
