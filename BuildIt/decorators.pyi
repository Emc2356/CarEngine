from typing import Callable, Any, overload

from .build_spec_flags import BuildSpecFlags


@overload
def buildspec(flags: BuildSpecFlags) -> Callable: ...
@overload
def buildspec(func: Callable[[], Any]) -> Callable[[Callable[[], Any]], Any]: ...
@overload
def buildspec(flags: BuildSpecFlags, condition: bool) -> Callable[[Callable[[], Any]], Any]: ...
@overload
def buildspec(flags: BuildSpecFlags, condition_callback: Callable[[], bool]) -> Callable[[Callable[[], Any]], Any]: ...
