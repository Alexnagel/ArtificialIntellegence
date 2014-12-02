//
//  Pill.h
//  Week2
//
//  Created by Alex Nagelkerke on 30-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#ifndef __Week2__Pill__
#define __Week2__Pill__

class Pill {
public:
    Pill();
    
    bool isEaten();
    void setEaten();
private:
    bool eaten;
};

#endif /* defined(__Week2__Pill__) */
