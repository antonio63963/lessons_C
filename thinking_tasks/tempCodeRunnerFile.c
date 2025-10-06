  int p12 = (p1 + p2) < k && p3 <= 100;
  int p13 = (p3 + p1) < k && p2 <= 100;
  int p23 = (p3 + p2) < k && p1 <= 100;

  // int isCan = ((p1 + p2) < k && (p3 + p1) < k) || ((p1 + p2) < k && (p3 + p2) < k) || (p1 + p3);
  int isCan = (p12 && p13) || (p12 && p23) || (p23 && p13);