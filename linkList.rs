#[derive(Debug)]
struct LinkList {
    val: i32,
    nextPointer: Option<Box<LinkList>>,
}
impl LinkList {
    fn new(val: i32) -> LinkList {
        LinkList {
            val: val,
            nextPointer: None,
        }
    }
}
fn vec_to_LinkList(num: Vec<i32>) -> Option<Box<LinkList>> {
    let mut nextPointer = None;
    for i in num.into_iter().rev() {
        let mut tmp: LinkList = LinkList::new(i);
        tmp.nextPointer = nextPointer;
        nextPointer = Some(Box::new(tmp));
    }
    return nextPointer;
}
fn main() {
    let arrayData: Vec<i32> = vec![1, 2, 3, 4, 5];
    print!("{:?}", vec_to_LinkList(arrayData));
}
