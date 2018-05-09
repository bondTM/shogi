use std::os::raw::*;

const SPACE: i8 = 0;

#[derive(Copy, Clone)]
#[repr(C)]
#[allow(non_snake_case)]
pub struct Square {
    piece: c_char,		//駒の種類
	owner: c_char,		//駒の所有者
    isChosen: c_char,	//駒が選択されているか
}

pub fn new() -> Square{
    Square{piece:SPACE ,owner:SPACE, isChosen:SPACE}
}