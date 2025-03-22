use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;

fn inputdataStream() -> Vec<Option<i32>> {
    let mut input: String = String::new();
    std::io::stdin().read_line(&mut input);
    let returnVec: Vec<Option<i32>> = input.trim().split(",").map(|x| x.parse().ok()).collect();
    return returnVec;
}
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    fn new(val: i32) -> Rc<RefCell<TreeNode>> {
        Rc::new(RefCell::new(TreeNode {
            val,
            left: None,
            right: None,
        }))
    }
}
fn recover_tree(root: &mut Option<Rc<RefCell<TreeNode>>>) {}

fn main() {
    let treeData: Vec<Option<i32>> = inputdataStream();
    let mut quee: VecDeque<Rc<RefCell<TreeNode>>> = VecDeque::new();

    let root = TreeNode::new(treeData[0].unwrap());
    quee.push_back(Rc::clone(&root));

    let mut i = 1;
    while i < treeData.len() {
        if let Some(parent) = quee.pop_front() {
            print!( "Parent => {}", Rc::<RefCell<TreeNode>>try_unwrap(parent).unwrap_err());
            let left_child = TreeNode::new(treeData[i].unwrap());
            parent.borrow_mut().left = Some(Rc::clone(&left_child));
            quee.push_back(left_child);

            let right_child = TreeNode::new(treeData[i + 1].unwrap());
            parent.borrow_mut().right = Some(Rc::clone(&right_child));
            quee.push_back(right_child);
        }
        i += 2;
    }
}
