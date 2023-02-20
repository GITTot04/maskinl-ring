<script setup lang="ts">
import { StreamBarcodeReader } from "vue-barcode-reader";

</script>

<template>
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
