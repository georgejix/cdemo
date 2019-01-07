/*
 * innerclass.h
 *
 *  Created on: 2019年1月7日
 *      Author: Administrator
 */

#ifndef SRC_INNERCLASS_H_
#define SRC_INNERCLASS_H_

class innerclass {
public:
	innerclass();
	virtual ~innerclass();
	class inner{
	public:
		void show();
	};
};

#endif /* SRC_INNERCLASS_H_ */
