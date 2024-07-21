function imADD(img1, img2, map_fn) {
  let final_img = new cv.Mat();
  cv.add(img1, img2, final_img);
  if (map_fn === 1) {
    cv.min(
      final_img,
      new cv.Mat(
        final_img.rows,
        final_img.cols,
        final_img.type(),
        new cv.Scalar(255)
      ),
      final_img
    );
  } else if (map_fn === 2) {
    let minMax = cv.minMaxLoc(final_img);
    cv.normalize(final_img, final_img, 0, 255, cv.NORM_MINMAX);
  }
  return final_img;
}

function imSUB(img1, img2, map_fn) {
  let final_img = new cv.Mat();
  cv.subtract(img1, img2, final_img);
  if (map_fn === 1) {
    cv.max(
      final_img,
      new cv.Mat(
        final_img.rows,
        final_img.cols,
        final_img.type(),
        new cv.Scalar(0)
      ),
      final_img
    );
  } else if (map_fn === 2) {
    let minMax = cv.minMaxLoc(final_img);
    cv.normalize(final_img, final_img, 0, 255, cv.NORM_MINMAX);
  }
  return final_img;
}

function imDIFF(img1, img2, map_fn) {
  let final_img = new cv.Mat();
  cv.absdiff(img1, img2, final_img);
  if (map_fn === 2) {
    let minMax = cv.minMaxLoc(final_img);
    cv.normalize(final_img, final_img, 0, 255, cv.NORM_MINMAX);
  }
  return final_img;
}

function imMULTIPLY(img1, img2, map_fn) {
  let final_img = new cv.Mat();
  cv.multiply(img1, img2, final_img);
  if (map_fn === 1) {
    cv.min(
      final_img,
      new cv.Mat(
        final_img.rows,
        final_img.cols,
        final_img.type(),
        new cv.Scalar(255)
      ),
      final_img
    );
  } else if (map_fn === 2) {
    let minMax = cv.minMaxLoc(final_img);
    cv.normalize(final_img, final_img, 0, 255, cv.NORM_MINMAX);
  }
  return final_img;
}

function imDIVIDE(img1, img2, map_fn) {
  let final_img = new cv.Mat();
  cv.divide(img1, img2, final_img);
  if (map_fn === 1) {
    cv.min(
      final_img,
      new cv.Mat(
        final_img.rows,
        final_img.cols,
        final_img.type(),
        new cv.Scalar(255)
      ),
      final_img
    );
  } else if (map_fn === 2) {
    let minMax = cv.minMaxLoc(final_img);
    cv.normalize(final_img, final_img, 0, 255, cv.NORM_MINMAX);
  }
  return final_img;
}

async function processImages(primaryImg, secondaryImg, opt, fitting) {
  var state = parseInt(localStorage.getItem("state"));
  let resultImage = null;
  // switch (parseInt(opt)) {
  //   case 1:
  //     resultImage = imADD(primaryImg, secondaryImg, parseInt(fitting));
  //     break;
  //   case 2:
  //     resultImage = imSUB(primaryImg, secondaryImg, parseInt(fitting));
  //     break;
  //   case 3:
  //     resultImage = imDIFF(primaryImg, secondaryImg, parseInt(fitting));
  //     break;
  //   case 4:
  //     resultImage = imMULTIPLY(primaryImg, secondaryImg, parseInt(fitting));
  //     break;
  //   case 5:
  //     resultImage = imDIVIDE(primaryImg, secondaryImg, parseInt(fitting));
  //     break;
  //   default:
  //     console.error("Invalid operation");
  //     return;
  // }
  resultImage = primaryImg;

  // cv.imwrite(userFolder + userId + "_" + (state + 1) + ".png", resultImage);

  let opern = [
    "",
    "Addition and ",
    "Subtraction and ",
    "Difference and ",
    "Multiplication and ",
    "Division and ",
  ][opt];
  let map_fn = ["", "Clipping", "Auto-Scaling"][fitting];

  let content = `<div class="item">
        <h2>Primary Image</h2>
        <img id="primaryImage" alt="picture" width="140px" height="140px"/>
      </div>
      <div class="item">
        <h2>Secondary Image</h2>
        <img id="secondaryImage" alt="picture" width="140px" height="140px"/>
      </div>
      <div class="item">
        <h2>Processed Image</h2>
        <img id="processedImage" alt="picture" width="140px" height="140px"/>
        <dl class="details ui-helper-clearfix"><dt>${opern}${map_fn}</dt></dl>
      </div><br><br>`;

  $("#sliderContent").html(content);

}
