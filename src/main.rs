mod rust_gui;

use rust_gui::*;

#[link(name="Shogi.Core")]
#[no_mangle]
extern "stdcall"{
    fn init(sqwk: [[square::Square; 9]; 9]);
}

fn main() {
    let sq_wk = [[square::new(); 9]; 9];

    unsafe{
        init(sq_wk);
    }

    println!("Hello, world!");
}
