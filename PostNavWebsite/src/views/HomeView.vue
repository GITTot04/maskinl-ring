<script setup lang="ts">
import ScanCam from "../components/ScanCam.vue";
import RecentScans from "../components/RecentScans.vue";
import Selected from "../components/Selected.vue";

</script>

<template>
  <main>
    <body>
    <div class="left-section">
      <ScanCam class="cam-section"></ScanCam>
      <RecentScans class="RecentsScans-section"></RecentScans>
    </div>
    <div class="right-section">
    <Selected></Selected>
    </div>
  </body>
  </main>
</template>

<style scoped>
body {
  display: flex;
  flex-direction: row;
  height: 100vh;
  color: black;
}

.left-section {
  display: flex;
  flex-flow: column;
  height: 100%;
  width: 50%;
  background-color: #F1F1F1;
  text-align: center;
  padding: 25px;
}

.right-section {
  width: 50%;
  background-color: #E0CBB8;
  text-align: center;
  min-height: 500px;
}

@media (max-width: 1400px) {
  body {
    flex-direction: column;
    height: 100vh;
  }

  .left-section,
  .right-section {
    width: 100%;
    min-height: 1000px;
    height: 100%;
    display:block;
  }
  .RecentsScans-section {
  width: 100%;
  height: 45vh;
  background-color: rgb(209, 129, 24);
  text-align: center;
  bottom: 0%;
}

}

.cam-section {
  display: flex;
  flex-flow: column;
  width: 100%;
  height: 0;
  padding-bottom: 56.25%;
  position: relative;
  border-radius: 19px;
  box-shadow: 10px;
  filter: drop-shadow(0px 5px 8px rgba(0, 0, 0, 0.25));
  z-index: 1;
}

.RecentsScans-section {
  width: 100%;
  background-color:#E0CBB8;
  border-radius: 19px;
  text-align: center;
  bottom: 0%;
  min-height: 350px;
  margin-top: -20px;
  padding-top: 20px;
}
</style>
