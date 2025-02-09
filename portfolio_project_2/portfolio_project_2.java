package portfolio_project_2;

import java.util.concurrent.CountDownLatch;

public class portfolio_project_2 {
    private static int counter = 0;

    public static void main(String[] args) {
        // similar to condition variable in c++
        CountDownLatch latch = new CountDownLatch(1);

        Thread countUpThread = new Thread(() -> countUp(latch));
        Thread countDownThread = new Thread(() -> countDown(latch));

        countUpThread.start();
        countDownThread.start();
    }

    private static void countUp(CountDownLatch latch) {
        // count up
        for (; counter < 20; counter++) {
            System.out.println("up: " + counter);
        }
        // signal that up is finished
        System.out.println("up finished: " + counter);
        latch.countDown(); 
    }

    private static void countDown(CountDownLatch latch) {
        // wait for up to finish
        try {
            latch.await(); 
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
        // count down
        for (; counter > 0; counter--) {
            System.out.println("down: " + counter);
        }
        System.out.println("down finished: " + counter);
    }
}
