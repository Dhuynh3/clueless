# Clueless

Clueless enumerates through Windows HWND and makes them visible for applications to screenshot/view.

## Why?

This project was a fun impelementation of how easily
detectable hidden overlays are. The project's name is a play on words for Cluely https://cluely.com/ a software developed by Roy Lee, who makes hiden desktop applications with AI integration for tasks such as meetings, cheating on LC, etc.

And yes this detects InterviewCoder.

## Technical Details

Clueless uses Win32 API `EnumWindows`, `GetWindowDisplayAffinity` and `SetWindowDisplayAffinity`
to check and change Windows affinity.

## Improvements

It is possible in kernel mode to use undocumented functions to set a Windows affinity to `WDA_EXCLUDEFROMCAPTURE` without having the changed affinity reflected when using `GetWindowDisplayAffinity`.

## Discussion

The cat and mouse game is never ending, there are extremely unique ways to hide overlays with some people resorting to a glass looking box through type 1 hypervisor. I won't go into much details and will leave it for the reader to investigate.

I would like to thank the UC community for all their experience and tips.
