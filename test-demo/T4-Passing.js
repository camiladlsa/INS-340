// T4-Passing

class Stack{
    constructor() {
        this.top = -1;
        this.items = {}; 
    }
}

describe ('My Stack', () =>{

    it('is created empty', () => {
        const stack = new Stack();

        expect(stack.top).toBe(-1);
        expect(stack.items).toEqual({});
    });

    it.todo('can push to the top');
    it.todo('can pop off');
} )