//
//  InteractionBehaviour.cpp
//  SenderoInteractionClient
//
//  Created by Christian Bouvier on 9/16/15.
//
//

#include "InteractionBehaviour.h"

#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>     /* atof */
#include <vector>

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

InteractionBehaviour::InteractionBehaviour(){
    radius = 30;
}

InteractionBehaviour::~InteractionBehaviour(){
}

void InteractionBehaviour::customSetup (map<int,Pixel*>* pixels, vector<Pixel*>* pixelsFast) {
    
}

void InteractionBehaviour::update() {

    static float t = 0;

    float r = 255 * (sin(t * 4.12456654) + 1) / 2;
    float g = 255 - (255 * (sin(t * 5.313) + 1) / 2);
    float b = 255 * (sin(t * 9.125412) + 1) / 2;
    t += 0.007;

    for(int i = 0; i < pixelsFast->size(); i++){
        Pixel* px = (*pixelsFast)[i];
        px->blendRGBA(r,g,b,255,1);
    }

}

void InteractionBehaviour::draw() {
}

void InteractionBehaviour::keyPressed(int key){
    //sample -> paint every pixel with red at key pressed and blend with black at update
    vector<Pixel*>::iterator it = this->pixelsFast->begin();
    
    while (it!=this->pixelsFast->end()){
        Pixel* px = *it;
        px->blendRGBA(255, 0, 255, 255, 1.0f);
        it++;
    }
    //end of sample
    
}

void InteractionBehaviour::exit() {
    SpecificBehaviour::exit();
}