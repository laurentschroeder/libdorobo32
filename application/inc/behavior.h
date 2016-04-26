/*
 * behavior.h
 *
 *  Created on: Apr 25, 2016
 *      Author: laurent
 */

#ifndef INC_BEHAVIOR_H_
#define INC_BEHAVIOR_H_

extern void handle_bumpers(void);

typedef enum {
  geradeaus,
  links,
  rechts,
  stop,
  rueckwaerts,
  drehen
}motorflag_t;

#endif /* INC_BEHAVIOR_H_ */
