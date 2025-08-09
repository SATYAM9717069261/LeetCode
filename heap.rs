use std::cmp::Reverse;
use std::collections::BinaryHeap;

pub struct MinHeap<T: Ord> {
    heap: BinaryHeap<Reverse<T>>,
    cap: Option<usize>, // Optional for fixed size
}

impl<T: Ord> MinHeap<T> {
    pub fn new(cap: Option<usize>) -> Self {
        Self {
            heap: BinaryHeap::new(),
            cap,
        }
    }

    pub fn push(&mut self, val: T) {
        self.heap.push(Reverse(val));
        if let Some(k) = self.cap {
            if self.heap.len() > k {
                self.heap.pop(); // pop largest (Reverse wraps smallest)
            }
        }
    }

    pub fn pop(&mut self) -> Option<T> {
        self.heap.pop().map(|r| r.0)
    }

    pub fn peek(&self) -> Option<&T> {
        self.heap.peek().map(|r| &r.0)
    }

    pub fn len(&self) -> usize {
        self.heap.len()
    }
}

pub struct MaxHeap<T: Ord> {
    heap: BinaryHeap<T>,
    cap: Option<usize>,
}

impl<T: Ord> MaxHeap<T> {
    pub fn new(cap: Option<usize>) -> Self {
        Self {
            heap: BinaryHeap::new(),
            cap,
        }
    }

    pub fn push(&mut self, val: T) {
        self.heap.push(val);
        if let Some(k) = self.cap {
            if self.heap.len() > k {
                self.heap.pop(); // pop smallest of the largest
            }
        }
    }

    pub fn pop(&mut self) -> Option<T> {
        self.heap.pop()
    }

    pub fn peek(&self) -> Option<&T> {
        self.heap.peek()
    }

    pub fn len(&self) -> usize {
        self.heap.len()
    }
}
