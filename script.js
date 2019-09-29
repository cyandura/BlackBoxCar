document.onkeydown = checkKey;
document.onkeyup = keyUp;
function checkKey(e) {

    e = e || window.event;

    switch (e.key) {
        case "ArrowLeft":
            // Left pressed
            document.getElementById("left").className += " " + "pressed";
            break;
        case "ArrowRight":
            // Right pressed
            document.getElementById("right").className += " " + "pressed";
            break;
        case "ArrowUp":
            // Up pressed
            document.getElementById("up").className += " " + "pressed";
            break;
        case "ArrowDown":
            // Down pressed
            document.getElementById("down").className += " " + "pressed";
            break;
    }

}
function keyUp(e) {

    e = e || window.event;

    switch (e.key) {
        case "ArrowLeft":
            // Left pressed
            document.getElementById("left").className -= " " + "pressed";
            break;
        case "ArrowRight":
            // Right pressed
            document.getElementById("right").className -= " " + "pressed";
            break;
        case "ArrowUp":
            // Up pressed
            document.getElementById("up").className -= " " + "pressed";
            break;
        case "ArrowDown":
            // Down pressed
            document.getElementById("down").className -= " " + "pressed";
            break;
    }

}