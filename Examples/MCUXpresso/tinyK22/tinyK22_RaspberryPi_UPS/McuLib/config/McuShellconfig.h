#ifndef __McuShell_CONFIG_H
#define __McuShell_CONFIG_H

#ifndef McuShell_CONFIG_BLOCKING_SEND_ENABLED
  #define McuShell_CONFIG_BLOCKING_SEND_ENABLED            (1)
    /*!< 1: Sending is blocking (with an optional timeout); 0: Do not block on sending */
#endif

#ifndef McuShell_CONFIG_BLOCKING_SEND_TIMEOUT_MS
  #define McuShell_CONFIG_BLOCKING_SEND_TIMEOUT_MS         (20)
    /*!< Total blocking time (timeout) in milliseconds, uses 0 for blocking without a timeout */
#endif

#ifndef McuShell_CONFIG_BLOCKING_SEND_TIMEOUT_WAIT_MS
  #define McuShell_CONFIG_BLOCKING_SEND_TIMEOUT_WAIT_MS    (5)
    /*!< waiting time during blocking, use 0 (zero) for polling */
#endif

#ifndef McuShell_CONFIG_BLOCKING_SEND_RTOS_WAIT
  #define McuShell_CONFIG_BLOCKING_SEND_RTOS_WAIT          (1)
    /*!< 1: Use WaitmsOS() instead of Waitms(); 0: Use Waitms() instead of WaitOSms() */
#endif

#ifndef McuShell_CONFIG_USE_MUTEX
  #define McuShell_CONFIG_USE_MUTEX                        (0)
    /*!< 1: use RTOS mutex; 0: do not use RTOS mutex */
#endif

#ifndef McuShell_CONFIG_DEFAULT_SHELL_BUFFER_SIZE
  #define McuShell_CONFIG_DEFAULT_SHELL_BUFFER_SIZE        (48)
    /*!< default buffer size for shell command parsing */
#endif

#ifndef McuShell_CONFIG_DEFAULT_SERIAL
  #define McuShell_CONFIG_DEFAULT_SERIAL                   (0)
    /*!< 1: the shell implements its own StdIO which is returned by GetStdio(); 0: The shell does not implement its own standard I/O */
#endif

#if McuShell_CONFIG_DEFAULT_SERIAL
  #ifndef McuShell_CONFIG_DEFAULT_SERIAL_INCLUDE
    #define McuShell_CONFIG_DEFAULT_SERIAL_INCLUDE         "McuSerial.h"
      /*!< Include for the functions below */
  #endif

  #ifndef McuShell_CONFIG_DEFAULT_SERIAL_RECEIVE_FCT_NAME
    #define McuShell_CONFIG_DEFAULT_SERIAL_RECEIVE_FCT_NAME McuSerial_RecvChar
      /*!< Function name to read a character and returning ERR_OK if it was successful */
  #endif

  #ifndef McuShell_CONFIG_DEFAULT_SERIAL_SEND_FCT_NAME
    #define McuShell_CONFIG_DEFAULT_SERIAL_SEND_FCT_NAME   McuSerial_SendChar
      /*!< Function name to send a character and returning ERR_OK if it was successful */
  #endif

  #ifndef McuShell_CONFIG_DEFAULT_SERIAL_RXAVAIL_FCT_NAME
    #define McuShell_CONFIG_DEFAULT_SERIAL_RXAVAIL_FCT_NAME McuSerial_GetCharsInRxBuf
    /*!< Function name to check if there is anything available to receive and returns TRUE, otherwise FALSE */
  #endif
#endif

#ifndef McuShell_CONFIG_PROMPT_STRING
  #define McuShell_CONFIG_PROMPT_STRING                    "CMD> "
#endif

#ifndef McuShell_CONFIG_PROJECT_NAME_STRING
  #define McuShell_CONFIG_PROJECT_NAME_STRING              "My Project Name"
#endif

#ifndef McuShell_CONFIG_MULTI_CMD_ENABLED
  #define McuShell_CONFIG_MULTI_CMD_ENABLED                (0) /* 1: enabled, 0: disabled */
#endif

#ifndef McuShell_CONFIG_MULTI_CMD_SIZE
  #define McuShell_CONFIG_MULTI_CMD_SIZE                   (32) /* max size of each command */
#endif

#ifndef McuShell_CONFIG_MULTI_CMD_CHAR
  #define McuShell_CONFIG_MULTI_CMD_CHAR                   ';' /* separation character */
#endif


#endif /* __McuShell_CONFIG_H */
