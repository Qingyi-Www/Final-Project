import processing.video.*;

Movie myMovie;

void setup() {
  size(640, 360);
  myMovie = new Movie(this, "Controller - A 3-minute short film.mp4");
  myMovie.play();
}

void draw() {
  image(myMovie, 0, 0, width, height);
}

void movieEvent(Movie m) {
  m.read();
}
