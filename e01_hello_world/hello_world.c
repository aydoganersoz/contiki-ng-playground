#include <stdio.h>
#include "contiki.h"
#include "dev/leds.h"
#include "sys/etimer.h"

PROCESS(thread_1, "thread 1");
PROCESS(thread_2, "thread 2");
AUTOSTART_PROCESSES(&thread_1, &thread_2);

PROCESS_THREAD(thread_1, ev, data)
{
  static struct etimer timer;

  PROCESS_BEGIN();

  /* Setup a periodic timer that expires after 10 seconds. */
  etimer_set(&timer, CLOCK_SECOND * 10);

  while (1)
  {
    printf("I am thread 1\n");
    leds_toggle(LEDS_LED1);

    /* Wait for the periodic timer to expire and then restart the timer. */
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));
    etimer_reset(&timer);
  }

  PROCESS_END();
}

PROCESS_THREAD(thread_2, ev, data)
{
  static struct etimer timer;

  PROCESS_BEGIN();

  /* Setup a periodic timer that expires after 5 seconds. */
  etimer_set(&timer, CLOCK_SECOND * 5);

  while (1)
  {
    printf("I am thread 2\n");
    leds_toggle(LEDS_LED2);

    /* Wait for the periodic timer to expire and then restart the timer. */
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));
    etimer_reset(&timer);
  }

  PROCESS_END();
}
