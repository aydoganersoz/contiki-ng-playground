# Contiki-NG examples

## Terms

- `<target>` being a target that is [supported by Contiki-NG](https://github.com/contiki-ng/contiki-ng/wiki#the-contiki-ng-platforms)

- `<path_to_target_sdk>` being the full path where the related SDK is located

- `<example_dir_name>` being the relative path of the example directory with respect to the root directory

- `<CONTIKI_PROJECT>` being the application name in the application makefile as well as the application's source file name inside the example directory

## How to build an example

Export target SDK:

```bash
export <target>_SDK_ROOT=<path_to_target_sdk>
```

From the root directory:

```bash
make TARGET=<target> -C <example_dir_name>
```

## How to erase the flash

From the root directory:

```bash
make TARGET=<target> -C <example_dir_name> erase
```

## How to flash an example

From the root directory:

```bash
make TARGET=<target> -C <example_dir_name> <CONTIKI_PROJECT>.flash
```

## How to access STDIO via UART

From the root directory:

```bash
picocom -fh -b 115200 --imap lfcrlf /dev/ttyACM0
```

## Examples

### e01_hello_world

Hello world application. Two threads running in parallel, the first one having ten seconds of period whereas the second one having five seconds. Different LEDs are toggled inside threads. 
