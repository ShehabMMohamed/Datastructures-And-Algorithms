#include "MyHeap.h"

MyMinHeap::MyMinHeap() : capacity(50) {}

MyMinHeap::MyMinHeap(int input_size) : capacity(input_size) {}

void MyMinHeap::BubbleDown(int val) {}

void MyMinHeap::BubbleUp(int val) {}

bool MyMinHeap::insert_key(int k) {}

bool MyMinHeap::remove_key(int k) {}

int MyMinHeap::retrieve_min() { return V[0]; }

MyMinHeap::~MyMinHeap() {}


MyMaxHeap::MyMaxHeap() : capacity(50) {}

MyMaxHeap::MyMaxHeap(int input_size) : capacity(input_size) {}

void MyMaxHeap::BubbleDown(int val) {}

void MyMaxHeap::BubbleUp(int val) {}

bool MyMaxHeap::insert_key(int k) {}

bool MyMaxHeap::remove_key(int k) {}

int MyMaxHeap::retrieve_max() { return V[0]; }

MyMaxHeap::~MyMaxHeap() {}