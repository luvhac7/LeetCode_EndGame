type FooBar struct {
	n     int
	isFoo atomic.Bool
}

func NewFooBar(n int) *FooBar {
	return &FooBar{n: n, isFoo: atomic.Bool{}}
}

func (fb *FooBar) Foo(printFoo func()) {
	for i := 0; i < fb.n; i++ {
		for fb.isFoo.Load() {
			runtime.Gosched()
		}
		// printFoo() outputs "foo". Do not change or remove this line.
		printFoo()
		fb.isFoo.Store(true)
	}
}

func (fb *FooBar) Bar(printBar func()) {
	for i := 0; i < fb.n; i++ {
		for !fb.isFoo.Load() {
			runtime.Gosched()
		}
		printBar()
		fb.isFoo.Store(false)
	}
}
