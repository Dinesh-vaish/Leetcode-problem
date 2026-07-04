/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
    return function(...args) {
        let greting="Hello World";
        return greting;
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */