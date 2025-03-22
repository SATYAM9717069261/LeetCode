use std::collections::BinaryHeap;
struct SmallestRangeIterator<'a> {
    heap: BinaryHeap<Reverse<SparseRange<'a>>>,
    sup: i32,
}

impl<'a> SmallestRangeIterator<'a> {
    fn new(input_ranges: &'a [impl Deref<Target = [i32]>]) -> Self {
        Self {
            heap: input_ranges
                .iter()
                .map(|s| Reverse(SparseRange(s)))
                .collect::<BinaryHeap<_>>(),
            sup: input_ranges
                .iter()
                .filter_map(|s| s.first())
                .max()
                .copied()
                .unwrap_or(i32::MAX),
        }
    }
}

impl Iterator for SmallestRangeIterator<'_> {
    type Item = [i32; 2];

    fn next(&mut self) -> Option<Self::Item> {
        let head = self.heap.peek_mut()?;
        let [inf, sup] = [head.0.inf()?, self.sup];
        head.0.advance();
        if let Some(i) = head.0.inf() {
            self.sup = sup.max(i)
        }
        Some([inf, sup])
    }
}

fn main() {
    println!(
        "{:?}",
        smallest_range(vec![
            vec![4, 10, 15, 24, 26],
            vec![0, 9, 12, 20],
            vec![5, 18, 22, 30]
        ])
    );
}
