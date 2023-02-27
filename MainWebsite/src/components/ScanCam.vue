<script setup lang="ts">
import { ref } from "vue";
import { StreamBarcodeReader } from "vue-barcode-reader";

const CamIP = ref("");

function SaveIP(event) {
    CamIP.value = event.value;
}

</script>

<template>
  <div class="IPCam">
    <h1>Indtast Kameraets IP</h1>
    <input v-model="SaveIP" @submit="SaveIP" @keyup.enter="SaveIP" placeholder="edit me" />
  </div>
  <div class="Cam">
    <!--<StreamBarcodeReader @decode="onDecode" @loaded="onLoaded"></StreamBarcodeReader>-->
      <h1> Picture of what the camera sees omg so HD</h1>
  </div>
</template>

<style scoped>
.Cam {
  width: 100%;
  height: 100%;
  background-color: white;
}

</style>
