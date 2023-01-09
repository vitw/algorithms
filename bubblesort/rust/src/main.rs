use std::io;


fn bublesort(vec: &mut Vec<u32>, arr_size: usize){
    for _i in 0..(arr_size - 1) {
        for j in 0..(arr_size - 1)  {
            if vec[j] > vec[j + 1]{
                vec.swap(j, j+1);
                println!("swap(&mut array, {}, {}", j, j + 1);
            }
        }
    }
}

fn main() {
    let mut arr_size = String::new();
    io::stdin()
        .read_line(&mut arr_size)
        .expect("failed to read from stdin");
    let arr_size: usize = arr_size.trim().parse().expect("Input valid number");
    let mut vec = Vec::new();
    for _ in 0..arr_size{
        let mut arr_element = String::new();
        io::stdin()
            .read_line(&mut arr_element)
            .expect("failed to read from stdin");
        let arr_element: u32 = arr_element.trim().parse().expect("Input valid number");
        vec.push(arr_element);
    }

    println!("Before sorting: {:?}", vec);
    bublesort(&mut vec, arr_size);
    println!("After sorting: {:?}", vec);
}
